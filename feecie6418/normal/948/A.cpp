#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
char a[1005][1005];
int main()
{
	int r,c;
	cin>>r>>c;
	for(int i=1;i<=r;i++)scanf("%s",a[i]+1);
	for(int i=1;i<=r;i++){
		for(int j=1;j<=c;j++){
			if(a[i][j]=='W'){
				if(a[i-1][j]=='S'||a[i+1][j]=='S'||a[i][j+1]=='S'||a[i][j-1]=='S')return cout<<"No",0;
			}
		}
	}
	cout<<"Yes\n";
	for(int i=1;i<=r;i++){
		for(int j=1;j<=c;j++){
			if(a[i][j]=='.'){
				cout<<'D';
			}
			else cout<<a[i][j];
		}
		cout<<endl;
	}
}