#include<bits/stdc++.h>
using namespace std;
void work(){
	char s[211][211]={0};
	int x1,y1,x2,y2,x3,y3;
	cin>>x1>>y1>>x2>>y2>>x3>>y3;
	if(x1>y1)swap(x1,y1);
	if(x2>y2)swap(x2,y2);
	if(x3>y3)swap(x3,y3);
	int w=x1*y1+x2*y2+x3*y3;
	int n=0;
	while(n*n<w)++n;
#define GG {cout<<"-1\n";return;}
	if(n*n!=w||y1>n||y2>n||y3>n)GG;
	for(int i=0;i<x1;++i)
		for(int j=0;j<y1;++j)
			s[i][j]='A';
	if(y1<n){
		if(y2==n){
			if(x2==n-y1){
				if(y3!=y1)swap(x3,y3);
				if(y3!=y1)GG;
				for(int i=0;i<n;++i)for(int j=y1;j<n;++j)s[i][j]='B';
				for(int i=x1;i<n;++i)for(int j=0;j<y1;++j)s[i][j]='C';
			}else{
				if(x1+x2!=n)GG;
				if(x3!=x1)swap(x3,y3);
				if(x3!=x1)GG;
				for(int i=x1;i<n;++i)for(int j=0;j<n;++j)s[i][j]='B';
				for(int i=0;i<x1;++i)for(int j=y1;j<n;++j)s[i][j]='C';
			}
		}else if(y3==n){
			if(x3==n-y1){
				if(y2!=y1)swap(x2,y2);
				if(y2!=y1)GG;
				for(int i=0;i<n;++i)for(int j=y1;j<n;++j)s[i][j]='C';
				for(int i=x1;i<n;++i)for(int j=0;j<y1;++j)s[i][j]='B';
			}else{
				if(x1+x3!=n)GG;
				if(x2!=x1)swap(x2,y2);
				if(x2!=x1)GG;
				for(int i=x1;i<n;++i)for(int j=0;j<n;++j)s[i][j]='C';
				for(int i=0;i<x1;++i)for(int j=y1;j<n;++j)s[i][j]='B';
			
			}
		}else GG;
	}else{
		if(y2==n&&y3==n){
			for(int i=x1;i<x1+x2;++i)for(int j=0;j<n;++j)s[i][j]='B';
			for(int i=x1+x2;i<n;++i)for(int j=0;j<n;++j)s[i][j]='C';
		}else{
			if(x2!=n-x1)swap(x2,y2);
			if(x3!=n-x1)swap(x3,y3);
			if(x2!=x3||x2!=n-x1)GG;
			for(int i=x1;i<n;++i)for(int j=0;j<n;++j)s[i][j]=(j<y2)?'B':'C';
		}
	}
	cout<<n<<"\n";
	for(int i=0;i<n;++i)cout<<s[i]<<"\n";
}

int main(){
#ifdef flukehn
	freopen("a.in","r",stdin);
#endif
	ios::sync_with_stdio(0),cin.tie(0);
	int T;
#ifdef flukehn
	cin>>T;
#else
	T=1;
#endif
	while(T--){
		work();
	}
}