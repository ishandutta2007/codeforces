#include<bits/stdc++.h>
using namespace std;
long long t,n,pos,sum,pp,x[200005],rk[200005],occ[200005],rs[200005];
string s;
vector<long long>v,v2;
char ans[200005],rx[200005];
inline long long read(){
    register long long num=0,neg=1;
    register char ch=getchar();
    while(!isdigit(ch)&&ch!='-') ch=getchar();
    if(ch=='-') neg=-1,ch=getchar();
    while(isdigit(ch)) num=(num<<3)+(num<<1)+(ch-'0'),ch=getchar();
    return neg==1?num:-num;
} 
inline long long calc(long long x){
	long long ans=0;
	for(register int i=0;i<v.size();i++)ans+=abs(v[i]-x);
	return ans;
}
int main(){
	t=read();
	while(t--){
		cin>>s,n=read(),memset(rk,0,sizeof(rk)),memset(occ,0,sizeof(occ));
	    memset(rs,0,sizeof(rs)),memset(rx,0,sizeof(rx)),memset(ans,0,sizeof(ans));
	    v.clear(),sum=0,pp=1;
	    for(register int i=0;i<s.length();i++)occ[s[i]-'a']++;
	    for(register int i=1;i<=n;i++){
		    x[i]=read();
		    if(!x[i])rk[i]=1,v.push_back(i),sum++,rs[1]++;
	    }
	    while(sum!=n){
		    pp++,v2.clear();
		    for(register int i=1;i<=n;i++)if(!rk[i]&&calc(i)==x[i])v2.push_back(i),rk[i]=pp,sum++,rs[pp]++;
		    for(register int i=0;i<v2.size();i++)v.push_back(v2[i]);
	    }
	    for(register int i=1,j=25;i<=n;rx[i++]=j+'a',j--)while(occ[j]<rs[i])j--;
	    for(register int i=1;i<=n;i++)ans[i]=rx[rk[i]];
	    printf("%s\n",ans+1);
	}
}