#include<bits/stdc++.h>
using namespace std;
#define N 500010
#define M 125
typedef long long ll;
char s[N];
int n,zz[N];
int Get(int x){
    if(zz[x]!=-1)return zz[x];
    if(x==0||x==1)return zz[x]=0;
    if(x==2||x==3)return zz[x]=1;
	vector<bool> vis(M);
    for(int i=0;i<x-1;++i){
        vis[Get(i)^Get(x-i-2)]=true;
    }
    for(int i=0;;++i){
        if(!vis[i]){
			return zz[x]=i;
		}
    }
}
void init(int n){
	for(int i=0;i<=n;++i)zz[i]=-1;
	for(int i=0;i<=n;++i){
		zz[i]=Get(i);
	}
}
int get_sg(int x){
    return x<=120?zz[x]:zz[x%34+2*34];
}
void Solve(){
	cin>>n;
	cin>>(s+1);
	int R=0,B=0;
	for(int i=1;i<=n;++i){
		R+=s[i]=='R';
		B+=s[i]=='B';
	}
	if(R>B){
		cout<<"Alice\n";
	}
	else if(B>R){
		cout<<"Bob\n";
	}
	else{
		int p=0;
		vector<int> g;
		int len=1;
		for(int i=2;i<=n+1;++i){
			if(s[i]==s[i-1]||i==n+1){
				p^=get_sg(len);
				len=0;
			}
			++len;
		}
		if(p)cout<<"Alice\n";
		else cout<<"Bob\n";
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	init(120);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}