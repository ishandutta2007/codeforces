#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);

    static const int N = 2005;

    int n, k;
    cin>>n>>k;

    static char a[N][N];
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin>>a[i][j];
        }
    }

    static int order_in_diagonal[N][N];
    static int optimal_pointer[N][N]; // 0 for right, 1 for down
    for(int i=0; i<=n; i++)
    {
        order_in_diagonal[i][n] = order_in_diagonal[n][i] = N;
    }
    for(int d = 2*n-2; d>=0; d--)
    {
        vector<pair<int, int>> orders_of_pointer_by_character[26];

        for(int i = max(0, d - (n-1)); i < min(n, d+1); i++)
        {
            int j = d - i;
            if(order_in_diagonal[i+1][j] < order_in_diagonal[i][j+1])
            {
                optimal_pointer[i][j] = 1;
                orders_of_pointer_by_character[a[i][j]-'a'].push_back({order_in_diagonal[i+1][j], i});
            }
            else
            {
                optimal_pointer[i][j] = 0;
                orders_of_pointer_by_character[a[i][j]-'a'].push_back({order_in_diagonal[i][j+1], i});
            }
        }

        int curr_order = 0;
        for(int c=0; c<26; c++)
        {
            if(!orders_of_pointer_by_character[c].empty())
            {
                sort(orders_of_pointer_by_character[c].begin(), orders_of_pointer_by_character[c].end());

                for(auto it : orders_of_pointer_by_character[c])
                {
                    int i = it.second;
                    int j = d - i;

                    order_in_diagonal[i][j] = curr_order++;
                }
            }
        }
    }

    static int required_changes[N][N];
    for(int i=0; i<=n; i++)
    {
        required_changes[i][0] = required_changes[0][i] = N;
    }
    required_changes[0][1] = 0;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            required_changes[i+1][j+1] = min(required_changes[i][j+1], required_changes[i+1][j]) + ((a[i][j]=='a') ? 0 : 1);
        }
    }

    pair<int, int> optimal_path_delimiter = {0, 0};
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(min(required_changes[i][j+1], required_changes[i+1][j]) <= k &&
                (
                    i + j > optimal_path_delimiter.first + optimal_path_delimiter.second ||
                    (
                        i + j == optimal_path_delimiter.first + optimal_path_delimiter.second &&
                        order_in_diagonal[i][j] < order_in_diagonal[optimal_path_delimiter.first][optimal_path_delimiter.second]
                    )
                )
            )
            {
                optimal_path_delimiter = {i, j};
            }
        }
    }

    if(required_changes[n][n] <= k)
    {
        cout<<string(2*n-1, 'a');
        return 0;
    }

    string ans = string(optimal_path_delimiter.first + optimal_path_delimiter.second, 'a');
    ans.push_back(a[optimal_path_delimiter.first][optimal_path_delimiter.second]);
    while(optimal_path_delimiter != make_pair(n-1, n-1))
    {
        if(optimal_pointer[optimal_path_delimiter.first][optimal_path_delimiter.second])
        {
            optimal_path_delimiter.first++;
        }
        else
        {
            optimal_path_delimiter.second++;
        }
        ans.push_back(a[optimal_path_delimiter.first][optimal_path_delimiter.second]);
    }

    cout<<ans;

    return 0;
}