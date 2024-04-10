#include <bits/stdc++.h>
#define N 105
using namespace std;
string str[N];
int n;
int main() {
    string now;
    cin>>now;
    cin >> n;
    for(int i=1;i<=n;i++) cin >> str[i];
    for(int i=1;i<=n;i++) if(now==str[i]) {
		puts("YES");
		return 0;
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            if(now[0]==str[i][1] && now[1]==str[j][0]) {
     			puts("YES");
				return 0;
            }
	puts("NO");
	return 0;
}