#include<iostream>
#include<map>
using namespace std;
map<string,int>id;
bool a[2][1001][5001];
int n,m;
int ans[2][1001];
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m;
	string name,crap,val,cur=" ",name2="";
	int op;
	for(int i=1; i<=n ;i++){
		cin >> name;
		id[name]=i;
		cin >> crap;
		getline(cin,val);
		val=val+' ';
		op=2;
		for(int j=0; j<val.size() ;j++){
			if(val[j]=='0' || val[j]=='1'){
				cur=cur+(char)(val[j]-48);
			}
			else if(val[j]=='?'){
				for(int x=0; x<=1 ;x++){
					for(int k=1; k<=m ;k++){
						if(op==1) a[x][k][i]=a[x][k][i]^x;
						else if(op==2) a[x][k][i]=a[x][k][i]|x;
						else a[x][k][i]=a[x][k][i]&x;
					}
				}
			}
			else if(val[j]>='a' && val[j]<='z'){
				name2=name2+val[j];
			}
			else if(val[j]=='X'){
				op=1;j+=3;
			}
			else if(val[j]=='O'){
				op=2;j+=2;
			}
			else if(val[j]=='A'){
				op=3;j+=3;
			}
			else if(val[j]==' ' && !name2.empty()){
				int newi=id[name2];
				for(int x=0; x<=1 ;x++){
					for(int k=1; k<=m ;k++){
						if(op==1) a[x][k][i]=a[x][k][i]^a[x][k][newi];
						else if(op==2) a[x][k][i]=a[x][k][i]|a[x][k][newi];
						else a[x][k][i]=a[x][k][i]&a[x][k][newi];
					}
				}
				name2="";
			}
			if(cur.size()==m+1){
				for(int x=0; x<=1 ;x++){
					for(int k=1; k<=m ;k++){
						if(op==1) a[x][k][i]=a[x][k][i]^cur[k];
						else if(op==2) a[x][k][i]=a[x][k][i]|cur[k];
						else a[x][k][i]=a[x][k][i]&cur[k];
					}
				}
				cur=" ";
			}
		}
	}
	for(int i=1; i<=n ;i++){
		for(int j=1; j<=m ;j++){
			for(int k=0; k<=1 ;k++){
				ans[k][j]+=a[k][j][i];
				
			}
		}
	}
	for(int i=1; i<=m ;i++){
		if(ans[0][i]<=ans[1][i]) cout << 0;
		else cout << 1;
	}
	cout << endl;
	for(int i=1; i<=m ;i++){
		if(ans[0][i]>=ans[1][i]) cout << 0;
		else cout << 1;
	}
	cout << endl;
}