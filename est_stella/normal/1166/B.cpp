#include<bits/stdc++.h>
using namespace std;

int k;
char d[5] = {'a', 'e', 'i', 'o', 'u'};

int main()
{
    scanf("%d", &k);

    for(int i=1; i<=k; i++)
    {
        if(k%i) continue;

        int r = i;
        int c = k/i;

        if( r < 5 || c < 5 ) continue;

        string ans;

        for(int j=0; j<r; j++)
        {
            for(int l=0; l<c; l++)
            {
                ans += d[(j+l)%5];
            }
        }

        cout<<ans;
        return 0;
    }

    cout << -1;
}