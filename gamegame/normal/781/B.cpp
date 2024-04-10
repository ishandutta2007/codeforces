#include<iostream>
#include<map>
using namespace std;
int n,k;
map<string,int>m;
map<string,bool>m2;
char a[1001][4];
int choice[1001];
int main(){
    ios::sync_with_stdio(false);
    cin >> n;
    string s,t;
    string u="   ",v="   ";
    for(int i=1; i<=n ;i++){
    	cin >> s >> t;
    	a[i][0]=s[0];a[i][1]=s[1];a[i][2]=s[2];a[i][3]=t[0];
    	u[0]=a[i][0];u[1]=a[i][1];u[2]=a[i][2];
    	v[0]=a[i][0];v[1]=a[i][1];v[2]=a[i][3];
    	m[u]++;
	}
	for(int i=1; i<=n ;i++){
    	u[0]=a[i][0];u[1]=a[i][1];u[2]=a[i][2];
    	v[0]=a[i][0];v[1]=a[i][1];v[2]=a[i][3];
		if(m[u]==1) continue;
		if(m2[v]){
			cout << "NO\n";
			return 0;
		}
		choice[i]=2;
		m2[v]=true;
	}
	for(int k=1; k<=n ;k++)
	for(int i=1; i<=n ;i++){
    	u[0]=a[i][0];u[1]=a[i][1];u[2]=a[i][2];
    	v[0]=a[i][0];v[1]=a[i][1];v[2]=a[i][3];
		if(choice[i]!=0) continue;
		if(m2[u]){
			if(m2[v]){
				cout << "NO\n";
				return 0;
			}
			choice[i]=2;
			m2[v]=true;
		}
		else if(m2[v]){
			choice[i]=1;
			m2[u]=true;
		}
	}
	cout << "YES\n";
	for(int i=1; i<=n ;i++){
    	u[0]=a[i][0];u[1]=a[i][1];u[2]=a[i][2];
    	v[0]=a[i][0];v[1]=a[i][1];v[2]=a[i][3];
		if(choice[i]!=2){
			cout << u << endl;
		}
		else cout << v << endl;
	}
}