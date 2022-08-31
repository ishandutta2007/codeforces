#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
int n;
ll cnt[26],cc[26][26];
ll ans;
char s[maxn];

int main(){
    scanf("%s",s+1); n=strlen(s+1);
    for (int i=1;i<=n;i++){
        int x=s[i]-'a';
        for (int j=0;j<26;j++) cc[j][x]+=cnt[j];
        cnt[x]++;
    }
    for (int i=0;i<26;i++) ans=max(ans,cnt[i]);
    for (int i=0;i<26;i++)
        for (int j=0;j<26;j++)
            ans=max(ans,cc[i][j]);
    cout << ans << endl;
    return 0;
}