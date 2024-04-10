#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
#define fi first
#define se second
int n,b;
const int N=201,B=201;
string low[N],up[N];

int lvl[N+B];
string inc(string y){
	bool ok=false;
	for(auto& c:y){
		if(c=='0'){
			c='1';ok=true;break;
		}
		else c='0';
	}
	if(!ok) return "-1";
	return y;
}
string dec(string y){
	bool ok=false;
	for(auto& c:y){
		if(c=='1'){
			c='0';ok=true;break;
		}
		else c='1';
	}
	return y;
}
int ask(int x,string y){
	if(y=="-1") return 0;
	y=dec(y);
	if(y=="-1") return 1;
	reverse(y.begin(),y.end());
	cout << x << ' ' << y << endl;
	string res;cin >> res;
	return res=="yes";
}
void debug(){
	cout << "<debug>\n";
	for(int i=1; i<=n ;i++){
		cout << low[i] << ' ' << up[i] << endl;
	}
	for(int i=0; i<n+b ;i++){
		cout << lvl[i] << ' ';
	}
	cout << endl;
	cout << "</debug>" << endl;
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	cin >> n >> b;
	for(int i=1; i<=n ;i++){
		lvl[b+i-1]=i;
		for(int j=0; j<b ;j++){
			low[i]+='0';
			up[i]+='1';
		}
	}
	while(true){
		//debug();
		int x=n+b-1;
		while(lvl[x]==0) x--;
		int y=x;
		while(y>0 && lvl[y-1]) y--;
		//cout << x << ' ' << y << endl;
		int cx=lvl[x];
		int cy=lvl[y];
		while(y<x){
			cy=lvl[y];
			string tmp=up[cy];
			//cout << cy << ' ' << tmp << ' ' << inc(tmp) << " !!!" << endl;
			tmp=inc(tmp);
			if(ask(cx,tmp)){
				lvl[y]=0;y++;
			}
			else break;
		}
		if(x==y){
			for(int i=y-1; i>=0 ;i--){
				string tmp=low[cx];
				tmp[i]='1';
				if(ask(cx,tmp)) low[cx]=tmp;
			}
			reverse(low[cx].begin(),low[cx].end());
			cout << "0 " << low[cx] << endl;
			return 0;
		}
		if(y!=0){
			low[cx]=low[cy];
			up[cx]=up[cy];
			string tmp=low[cx];
			tmp[y-1]='1';
			if(ask(cx,tmp)){
				lvl[x]=0;
				lvl[y-1]=cx;
				low[cx]=tmp;
			}
			else{
				lvl[x]=0;
				lvl[y-1]=cx;
				up[cx][y-1]='0';
			}
		}
		else lvl[x]=0;
	}
}