#include<bits/stdc++.h>
using namespace std;
int n,cq;
char c[51];
string e="";
void ask(string s){
	cout << "? " << s << endl;
	int k;cin >> k;
	for(int i=1; i<=k ;i++){
		int x;cin >> x;
		for(int y=x; y<x+s.size() ;y++){
			if(c[y]=='?') cq--;
			c[y]=s[y-x];
		}
	}
	/*for(int i=1; i<=8 ;i++) cout << c[i];
	cout << endl;*/
}
void finish(string f,string b){
	if(c[1]=='?'){
		for(int i=0; i<f.size()-1 ;i++){
			char t=f[i];
			string s=e;s+=t;
			//cout << t << ' ' << s << ' ' << s.size() << endl;
			for(int j=2; j<=n ;j++) if(c[j]!='?') s+=c[j];
			//cout << s << endl;
			ask(s);
		}
		if(c[1]=='?') c[1]=f.back();
	}
	if(c[n]=='?'){
		for(int i=0; i<b.size()-1 ;i++){
			char t=b[i];
			string s=e;
			for(int j=1; j<n ;j++) if(c[j]!='?') s+=c[j];
			s+=t;
			ask(s);
		}
		if(c[n]=='?') c[n]=b.back();
	}
}
void solve(){
	if(n==4){
		ask("CC");ask("CH");ask("CO");ask("OH");//cost = 1
		if(cq==4){
			ask("HOO");
			if(cq==1){finish("OH","OC");return;}
			ask("HHH");
			if(cq==1){finish(e,"OC");return;}
			if(cq==0) return;
			ask("OOOO");
			if(cq==0) return;
			ask("HHOC");
			if(cq==0) return;
			c[1]='O';c[2]='O';c[3]='O';c[4]='C';
			cq=0;return;
		}
		else if(cq==0) return;
		else if(cq==1) finish("OH","OHC");
		else{
			if(c[3]=='?' && c[4]=='?'){
				ask(e+c[1]+c[2]+'H');
				ask(e+c[1]+c[2]+'O');
				if(c[3]=='?') c[3]='C';
				ask(e+c[1]+c[2]+c[3]+'H');
				ask(e+c[1]+c[2]+c[3]+'O');
				if(c[4]=='?') c[4]='C';
			}
			else if(c[1]=='?' && c[4]=='?'){
				ask(e+'H'+c[2]+c[3]);
				ask(e+'O'+c[2]+c[3]);
				if(c[1]=='?') c[1]='C';
				ask(e+c[1]+c[2]+c[3]+'H');
				ask(e+c[1]+c[2]+c[3]+'O');
				if(c[4]=='?') c[4]='C';
			}
			else{
				ask(e+'H'+c[3]+c[4]);
				ask(e+'O'+c[3]+c[4]);
				if(c[2]=='?') c[2]='C';
				ask(e+'H'+c[2]+c[3]+c[4]);
				ask(e+'O'+c[2]+c[3]+c[4]);
				if(c[1]=='?') c[1]='C';
			}
		}	
	}
	else{
		ask("CC");ask("CH");ask("CO");ask("OH");ask("HH");
		for(int i=2; i<=n-1 ;i++){
			if(c[i]=='?'){
				cq--;c[i]='O';
			}
		}
		finish("OH","OC");
	}
}
int main(){
	ios::sync_with_stdio(false);
	int t;cin >> t;
	while(t--){
		cin >> n;
		for(int i=1; i<=n ;i++) c[i]='?';
		cq=n;
		solve();
		cout << "! ";
		for(int i=1; i<=n ;i++) cout << c[i];
		cout << endl; 
		int mina;
		cin >> mina;
		if(mina==0) return 0;
	}
}