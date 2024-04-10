#include<iostream>
using namespace std;
int n;
int p[1000001];
bool vis[1000001];
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	int cnt=0;
	for(int i=1; i<=n ;i++){
		cin >> p[i];
	}
	int cc=0;
	for(int i=1; i<=n ;i++){
		if(!vis[i]){
			int cur=i;
			while(!vis[cur]){
				vis[cur]=true;
				cur=p[cur];
			}
			cc++;
		}
	}
	if(cc%2==0) cout << "Petr\n";
	else cout << "Um_nik\n"; 
}