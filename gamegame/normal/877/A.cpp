#include<iostream>
#include<queue>
#include<cmath>
#include<algorithm>
using namespace std;
int n,m,k;
string s;
string a[5]={"Danil", "Olya", "Slava", "Ann" ,"Nikita"};
int main(){
	ios::sync_with_stdio(false);
	getline(cin,s);
	int cnt=0;
	for(int i=0; i<5 ;i++){
		int x=s.find(a[i]);
		int y=s.find(a[i],x+1);
		cnt+=(x!=-1);
		cnt+=(y!=-1);
	}
	if(cnt==1) cout << "YES\n";
	else cout << "NO\n";
}