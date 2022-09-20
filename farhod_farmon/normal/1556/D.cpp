#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100100;

using namespace std;

bool off = false;
vector<int> A = {1, 6, 4, 2, 3, 5, 4};

int n, k;

int OR(int i, int j)
{
        if(off){
                return A[i] | A[j];
        }

        cout << "or " << i + 1 << " " << j+ 1 << endl;
        int x;
        cin >> x;
        return x;
}

int AND(int i, int j)
{
        if(off){
                return A[i] & A[j];
        }

        cout << "and " << i + 1 << " " << j + 1 << endl;
        int x;
        cin >> x;
        return x;
}

int a[N];

int main()
{
        #ifdef zxc
                freopen("input.txt", "r", stdin);
                freopen("output.txt", "w", stdout);
                off = true;
        #endif
        ios_base::sync_with_stdio(0);

        cin >> n >> k;

        vector<vector<int>> A(3, vector<int> (3, 0));
        vector<vector<int>> B(3, vector<int> (3, 0));
        for(int i = 0; i < 3; i++){
                for(int j = i + 1; j < 3; j++){
                        A[i][j] = A[j][i] = AND(i, j);
                        B[i][j] = B[j][i] = OR(i, j);
                }
        }

        for(int bit = 0; bit < 30; bit++){
                bool good = false;
                for(int i = 0; i < 3 && !good; i++){
                        for(int j = i + 1; j < 3 && !good; j++){
                                int h = 3 - i - j;
                                if(A[i][j] & (1 << bit)){
                                        good = true;
                                        a[i] |= (1 << bit);
                                        a[j] |= (1 << bit);
                                        if(((B[i][h] - A[i][h]) & (1 << bit)) == 0){
                                                a[h] |= (1 << bit);
                                        }
                                } else if((B[i][j] & (1 << bit)) == 0){
                                        good = true;
                                        if((B[i][h] - A[i][h]) & (1 << bit)){
                                                a[h] |= (1 << bit);
                                        }
                                }
                        }
                }
        }
        for(int i = 3; i < n; i++){
                a[i] = (OR(0, i) - AND(0, i)) ^ a[0];
        }
        sort(a, a + n);
        cout << "finish " << a[k - 1] << endl;
}