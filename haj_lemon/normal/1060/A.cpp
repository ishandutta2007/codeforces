#include<bits/stdc++.h>
using namespace std;
int n,x,y;
char ch;
int main(){
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>ch;
		if (ch=='8')x++;else y++;
	}
	cout<<min(x,(x+y)/11)<<endl;
	return 0;
}