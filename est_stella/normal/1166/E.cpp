#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<int> num[100];

int main()
{
    scanf("%d %d", &m, &n);

    for(int i=0; i<m; i++)
    {
        int k;
        scanf("%d", &k);

        for(int j=0; j<k; j++)
        {
            int x;
            scanf("%d", &x);

            num[i].push_back(x);
        }

        sort(num[i].begin(), num[i].end());
    }

    for(int i=0; i<m; i++)
    {
        for(int j=i+1; j<m; j++)
        {
            int x1 = 0;
            int x2 = 0;

            while(x1 < num[i].size() && x2 <num[j].size() && num[i][x1] != num[j][x2])
            {
                if(num[i][x1] < num[j][x2]) x1++;
                else x2++;
            }

            if(num[i][x1] != num[j][x2])
            {
                printf("impossible");
                return 0;
            }
        }
    }

    printf("possible");
}