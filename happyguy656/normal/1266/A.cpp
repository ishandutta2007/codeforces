#include<bits/stdc++.h>
using namespace std;
#define uu unsigned
#define scanf abc=scanf
#define fre(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define forg(i,x) for(int i=fir[x];i;i=nxt[i])
int abc;
typedef long long ll;
typedef uu long long ull;
typedef pair<int,int>pii;
typedef vector<int>VI;
mt19937 rnd((ull)(new char));
int rd(int l,int r){uniform_int_distribution<>ee(l,r);return ee(rnd);}

char s[222];int n;

bool chk(){
    int cc=0,sm=0,c2=0;
    for(int i=1;i<=n;++i)cc+=s[i]=='0',sm+=s[i]-'0',c2+=(s[i]-'0')%2==0;
    if(sm%3||!cc)return 0;
    if(c2==1)return 0;
    return 1;
}

int main(){
    int ca;cin>>ca;while(ca--){
        scanf("%s",s+1);n=strlen(s+1);puts(chk()?"red":"cyan");
    }
    return 0;
}