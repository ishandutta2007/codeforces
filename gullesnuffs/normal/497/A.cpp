#include <bits/stdc++.h>

using namespace std;

string s[105];
int n, m;

int main(){
	scanf("%d%d", &n, &m);
	for(int i=0; i < n; ++i)
		cin >> s[i];
	while(true){
		bool any=0;
		for(int i=0; i < n-1; ++i){
			if(s[i+1] < s[i]){
				any=1;
				for(int j=0; j < s[i].size(); ++j){
					if(s[i][j] > s[i+1][j]){
						for(int k=0; k < n; ++k){
							string ns="";
							for(int m=0; m < j; ++m)
								ns.push_back(s[k][m]);
							for(int m=j+1; m < s[k].size(); ++m)
								ns.push_back(s[k][m]);
							s[k]=ns;
						}
						break;
					}
				}
			}
		}
		if(!any)
			break;
	}
	printf("%d\n", m-s[0].size());
}