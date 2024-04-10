#include<algorithm>
#include<iostream>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define P 998244353
#define MAXN 200001
int N,M,a[MAXN],cnt[MAXN],tot,pos[MAXN],po[MAXN],has1[MAXN],has2[MAXN];
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
int val1(int l,int r){return (has1[r]-1ll*has1[l-1]*po[r-l+1]%P+P)%P;}int val2(int l,int r){return (has2[r]-1ll*has2[l-1]*po[r-l+1]%P+P)%P;}
bool check(int l1,int r1,int l2,int r2)
{
	if(cnt[r1]-cnt[l1-1]!=cnt[r2]-cnt[l2-1])return 0;if(cnt[r1]==cnt[l1-1]||cnt[r1]==cnt[l1-1]+r1-l1+1)return 1;
	int x1=lower_bound(pos+1,pos+tot+1,l1)-pos,y1=upper_bound(pos+1,pos+tot+1,r1)-pos-1,x2=lower_bound(pos+1,pos+tot+1,l2)-pos,y2=upper_bound(pos+1,pos+tot+1,r2)-pos-1;
	return ((l2-l1+1&1)&&val1(x1,y1)==val1(x2,y2)&&val2(x1,y1)==val2(x2,y2))||((l2-l1&1)&&val1(x1,y1)==val2(x2,y2)&&val2(x1,y1)==val1(x2,y2));
}
int main()
{
	N=get();string s;cin>>s;For(i,1,N)a[i]=s[i-1]-'0',cnt[i]=cnt[i-1]+(a[i]^1),a[i]==0?pos[++tot]=i:0;
	po[0]=1;For(i,1,tot)po[i]=po[i-1]*3ll%P,has1[i]=(has1[i-1]*3ll+(pos[i]&1)+1)%P,has2[i]=(has2[i-1]*3ll+((pos[i]&1)^1)+1)%P;
	M=get();For(i,1,M){int x=get(),y=get(),l=get();cout<<(check(x,x+l-1,y,y+l-1)?"YES\n":"NO\n");}return 0;
}