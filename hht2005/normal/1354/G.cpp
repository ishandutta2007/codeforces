#include<bits/stdc++.h>
using namespace std;
const int N=1010;
int st[N],top,f[N],Q[N];
int main() {
	int T;
	scanf("%d",&T);
	char S[10];
	while(T--) {
		memset(f,0,sizeof(f));
		int n,now=1;
		scanf("%d%*d",&n);
		for(int i=1;i<=30;i++) {
			int x=rand()%n+1;
			if(now==x) {
				i--;
				continue;
			}
			cout<<"? 1 1\n"<<now<<'\n'<<x<<endl;
			cin>>S;
			if(S[0]=='S')now=x;
		}
		f[st[top=1]=now]=1;
		while(1) {
			int cnt=0;
			for(int j=1;j<=n&&cnt<top;j++)
				if(!f[j])Q[++cnt]=j;
			cout<<"? "<<cnt<<' '<<cnt<<endl;
			for(int i=1;i<=cnt;i++)cout<<st[i]<<' ';cout<<endl;
			for(int i=1;i<=cnt;i++)cout<<Q[i]<<' ';cout<<endl;
			cin>>S;
			if(S[0]!='E') {
				int l=1,r=cnt;
				while(l<=r) {
					int mid=(l+r)>>1;
					cout<<"? "<<mid<<' '<<mid<<endl;
					for(int i=1;i<=mid;i++)cout<<st[i]<<' ';cout<<endl;
					for(int i=1;i<=mid;i++)cout<<Q[i]<<' ';cout<<endl;
					cin>>S;
					if(S[0]=='E')l=mid+1;
					else r=mid-1;
				}
				cout<<"! "<<Q[r+1]<<endl;
				break;
			}
			for(int i=1;i<=cnt;i++)
				f[st[++top]=Q[i]]=1;
		}
	}
	return 0;
}