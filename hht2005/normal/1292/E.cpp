#include<bits/stdc++.h>
using namespace std;
const int N=55;
char S[N];
int a,k,FL;
void dfs(int x) {
	if(x>4) {
		if(!FL)return;
		cout<<"? ";
		for(int i=1;i<=4;i++)
			cout<<S[i];
		cout<<endl;
		scanf("%d",&k);
		if(k) {
			scanf("%d",&a);
			FL=0;
			cout<<"! ";
			for(int i=1;i<=4;i++)
				cout<<S[i];
			cout<<endl;
		}
		return;
	}
	if(S[x]!='?')dfs(x+1);
	else {
		S[x]='H';
		dfs(x+1);
		S[x]='O';
		dfs(x+1);
		if(x==4) {
			S[x]='C';
			dfs(x+1);
		}
		S[x]='?';
	}
}
int main() {
	int T_T,n;
	scanf("%d",&T_T);
	while(T_T--) {
		memset(S,'?',sizeof(S));
		scanf("%d",&n);
		cout<<"? CC"<<endl;
		cout<<"? CO"<<endl;
		cout<<"? CH"<<endl;
		for(int T=1;T<=3;T++) {
			scanf("%d",&k);
			for(int i=1;i<=k;i++) {
				scanf("%d",&a);
				S[a]='C';
				if(T==1)S[a+1]='C';
				if(T==2)S[a+1]='O';
				if(T==3)S[a+1]='H';
			}
		}
		if(n==4) {
			cout<<"? HO"<<endl;
			scanf("%d",&k);
			for(int i=1;i<=k;i++) {
				scanf("%d",&a);
				S[a]='H';
				S[a+1]='O';
			}
			int cnt=0;
			for(int i=1;i<=n;i++)
				if(S[i]!='?')cnt++;
			FL=1;
			if(cnt)dfs(1);
			else {
				cout<<"? OO"<<endl;
				scanf("%d",&k);
				for(int i=1;i<=k;i++) {
					scanf("%d",&a);
					S[a]='O';
					S[a+1]='O';
				}
				if(S[n]=='O') {
					cout<<"! ";
					for(int i=1;i<=n;i++)
						cout<<S[i];
					cout<<endl;
				} else if(S[n-1]=='O') {
					cout<<"? OOOH"<<endl;
					scanf("%d",&k);
					if(k)scanf("%d",&a),cout<<"! OOOH"<<endl;
					else cout<<"! OOOC"<<endl;
				} else if(S[n-2]=='O') {
					cout<<"? OOHH"<<endl;
					scanf("%d",&k);
					if(k)scanf("%d",&a),cout<<"! OOHH"<<endl;
					else cout<<"! OOHC"<<endl;
				} else {
					S[2]=S[3]='H';
					S[1]='O';
					S[4]='C';
					cout<<"? HHH"<<endl;
					scanf("%d",&k);
					for(int i=1;i<=k;i++) {
						scanf("%d",&a);
						S[a]=S[a+1]=S[a+2]='H';
					}
					cout<<"! ";
					for(int i=1;i<=n;i++)
						cout<<S[i];
					cout<<endl;
				}
			}
			scanf("%*d");
			continue;
		}
		cout<<"? OH"<<endl;
		cout<<"? HH"<<endl;
		for(int T=1;T<=2;T++) {
			scanf("%d",&k);
			for(int i=1;i<=k;i++) {
				scanf("%d",&a);
				S[a+1]='H';
			}
		}
		for(int i=2;i<n;i++)
			if(S[i]=='?')S[i]='O';
		for(int i=0;i<2;i++)
			for(int j=0;j<2;j++) {
				if(S[1]=='C'&&i==0)continue;
				if(S[n]=='H'&&j==0)continue;
				if(S[1]!='C')S[1]=i?'H':'O';
				if(S[n]!='H')S[n]=j?'C':'O';
				if(i&&j)break;
				cout<<"? ";
				for(int i=1;i<=n;i++)
					cout<<S[i];
				cout<<endl;
				scanf("%d",&k);
				if(k==1) {
					scanf("%d",&a);
					i=2,j=2;
				}
			}
		cout<<"! ";
		for(int i=1;i<=n;i++)
			cout<<S[i];
		cout<<endl;
		scanf("%*d");
	}
	return 0;
}