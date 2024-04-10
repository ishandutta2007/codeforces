#include<bits/stdc++.h>
#define pb push_back
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;
const int maxn=3e5+10;
char s[maxn];
int n,q,l,r,cnt[26][maxn];

int main(){
    scanf("%s",s+1); n=strlen(s+1);
    for (int i=1;i<=n;i++){
        for (int j=0;j<26;j++) cnt[j][i]=cnt[j][i-1];
        cnt[s[i]-'a'][i]++;
    }
    scanf("%d",&q);
    while (q--){
        int l,r;scanf("%d%d",&l,&r);
        if (l==r){
            puts("Yes");
            continue;
        }
        int color=0;
        for (int i=0;i<26;i++)
            if (cnt[i][r]-cnt[i][l-1]>0) color++;
        if (color==1) puts("No");
        else if (color==2){
            if (s[l]==s[r]) puts("No"); else puts("Yes");
        } else {
            puts("Yes");
        }
    }
    return 0;
}