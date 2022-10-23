#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
const int mod=998244353,N=1e5;
char a1[N+5],a2[N+5];
int sumb1[N+5],sumb2[N+5],lsta1[N+5],lsta2[N+5];
int n,m,q;
int main(){
	scanf("%s%s%d",a1+1,a2+1,&q),n=strlen(a1+1),m=strlen(a2+1);
	for(int i=1;i<=n;i++){
		sumb1[i]=sumb1[i-1]+(a1[i]!='A');
		if(a1[i]=='A')lsta1[i]=lsta1[i-1]+1;
	}
	for(int i=1;i<=m;i++){
		sumb2[i]=sumb2[i-1]+(a2[i]!='A');
		if(a2[i]=='A')lsta2[i]=lsta2[i-1]+1;
	}
	for(int i=1;i<=q;i++){
		int l1,r1,l2,r2;
		scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
		int cb1=sumb1[r1]-sumb1[l1-1];
		int cb2=sumb2[r2]-sumb2[l2-1];
		int len1=min(lsta1[r1],r1-l1+1);
		int len2=min(lsta2[r2],r2-l2+1);
		if(cb2<cb1||cb2%2!=cb1%2||len2>len1||(cb1==cb2&&(len1-len2)%3)||(!cb1&&cb2&&len1==len2))cout<<0;
		else cout<<1;
	}
}