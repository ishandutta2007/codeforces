#include<bits/stdc++.h>
using namespace std;

int t, n, ans, cnt;
string s;

int main()
{
    scanf("%d", &t);

    for(int i=0; i<t; i++)
    {
        cin>>n>>s;

        cnt=0;
        for(int j=0; j<n; j++) {
            if(s[j]=='<') cnt++;
            else break;
        }
        ans=cnt;
        cnt=0;

        for(int j=n-1; j>=0; j--) {
            if(s[j]=='>') cnt++;
            else break;
        }

        if(ans > cnt) ans=cnt;

        printf("%d\n", ans);
    }
}