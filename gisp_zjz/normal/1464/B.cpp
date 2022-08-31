#include<bits/stdc++.h>
#define pb push_back
#define F first
#define S second
using namespace std;
const int maxn=1e5+100;
typedef long long ll;
ll ans,x,y;
int n;
int cp0[maxn],cp1[maxn],cs0[maxn],cs1[maxn]; //number of 0s
ll ap0[maxn],ap1[maxn],as0[maxn],as1[maxn]; // answer
char s[maxn];
int main(){
    cin >> s+1 >> x >> y;
    n=strlen(s+1);
    for (int i=1;i<=n;i++) {
        cp0[i]=cp0[i-1]+(s[i]!='1');
        if (cp0[i]==cp0[i-1]) ap0[i]=ap0[i-1]+x*cp0[i]; else ap0[i]=ap0[i-1]+y*(i-cp0[i]);
        cp1[i]=cp1[i-1]+(s[i]=='0');
        if (cp1[i]==cp1[i-1]) ap1[i]=ap1[i-1]+x*cp1[i]; else ap1[i]=ap1[i-1]+y*(i-cp1[i]);
    }
    for (int i=n;i;i--) {
        cs0[i]=cs0[i+1]+(s[i]!='1');
        if (cs0[i]==cs0[i+1]) as0[i]=as0[i+1]+y*cs0[i]; else as0[i]=as0[i+1]+x*((n-i+1)-cs0[i]);
        cs1[i]=cs1[i+1]+(s[i]=='0');
        if (cs1[i]==cs1[i+1]) as1[i]=as1[i+1]+y*cs1[i]; else as1[i]=as1[i+1]+x*((n-i+1)-cs1[i]);
    }
    ans=9e18;
    for (int i=0;i<=n;i++) {
        ans=min(ans,ap0[i]+as1[i+1]+x*cp0[i]*(n-i-cs1[i+1])+y*(i-cp0[i])*cs1[i+1]);
        ans=min(ans,ap1[i]+as0[i+1]+x*cp1[i]*(n-i-cs0[i+1])+y*(i-cp1[i])*cs0[i+1]);
    }
    cout << ans << endl;
    return 0;
}