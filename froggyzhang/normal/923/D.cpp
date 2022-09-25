#include<bits/stdc++.h>
using namespace std;
#define N 100020
typedef long long ll;
int n,m,a1[N],a2[N],c1[N],c2[N],Q;
char s1[N],s2[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>(s1+1)>>(s2+1);
	n=strlen(s1+1);
	m=strlen(s2+1);
	for(int i=1;i<=n;++i){
		a1[i]=a1[i-1]+(s1[i]=='B'||s1[i]=='C');	
		c1[i]=(s1[i]=='A'?c1[i-1]+1:0);
	}
	for(int i=1;i<=m;++i){
		a2[i]=a2[i-1]+(s2[i]=='B'||s2[i]=='C');
		c2[i]=(s2[i]=='A'?c2[i-1]+1:0);
	}
	cin>>Q;
	while(Q--){
		int l1,r1,l2,r2;
		cin>>l1>>r1>>l2>>r2;
		int t1=a1[r1]-a1[l1-1];	
		int t2=a2[r2]-a2[l2-1];
		int ed1=min(r1-l1+1,c1[r1]);
		int ed2=min(r2-l2+1,c2[r2]);
		if(t1>t2||(t1^t2)&1||ed1<ed2){
			cout<<0;
			continue;
		}
		if((ed1-ed2)%3&&t1==t2){
			cout<<0;
			continue;
		}
		if(!t1&&ed1==ed2&&t2){
			cout<<0;
			continue;
		}
		cout<<1;
	}
	return 0;
}