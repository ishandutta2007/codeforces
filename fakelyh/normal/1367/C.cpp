#include<bits/stdc++.h>
using namespace std;
long long t,n,kk,ans,l[200005],r[200005];
char ch[200005];
inline long long read(){
    register long long num=0,neg=1;
    register char ch=getchar();
    while(!isdigit(ch)&&ch!='-') ch=getchar();
    if(ch=='-') neg=-1,ch=getchar();
    while(isdigit(ch)) num=(num<<3)+(num<<1)+(ch-'0'),ch=getchar();
    return neg==1?num:-num;
} 
#define inf 1<<30
int main(){
	t=read();
	while(t--){
		n=read(),kk=read(),scanf("%s",ch+1),ans=0,l[0]=-inf,r[n+1]=inf;
	    for(register int i=1;i<=n;i++)l[i]=ch[i]=='1'?i:l[i-1];
	    for(register int i=n;i;i--)r[i]=ch[i]=='1'?i:r[i+1];
	    for(register int i=1;i<=n;i++){
		    if(ch[i]=='1')continue;
		    l[i]=l[i-1];
		    if(i-l[i]>kk&&r[i]-i>kk)ans++,l[i]=i;
	    }
	    printf("%d\n",ans);
	}
}