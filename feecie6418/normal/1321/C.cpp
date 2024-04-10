#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cstring>
#include<string>
using namespace std;
int n,ans;
char str[105];
int main() {
	cin>>n;
	for(int i=1; i<=n; i++)cin>>str[i];
	for(int i='z'; i>='a'; i--) {
		bool flag=1;
		while(flag) {
			flag=0;
			for(int j=1; j<=n; j++) {
				if(str[j]==i) {
					if(str[j-1]==i-1||str[j+1]==i-1) {
						ans++;
						for(int k=j; k<n; k++)str[k]=str[k+1];
						n--;
						flag=1;
						break;
					}
				}
			}
		}
	}
	cout<<ans;
}