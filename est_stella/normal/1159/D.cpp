#include<bits/stdc++.h>
using namespace std;

int n, k, cnt;

int main()
{
    scanf("%d%d", &n, &k);

    string ans;

    if(k==1)
    {
        ans = "1";
        for(int i=1; i<n; i++)
            ans+='0';

        cout << ans;
        return 0;
    }

    int l = (n - k + 2)/2;

    for(int i=0; i<n; i++)
    {
        if(cnt==0) ans+='1';
        else ans+='0';

        cnt++;
        cnt%=l;
    }

    cout << ans;
}