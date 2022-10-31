#include <iostream>
#include <iomanip>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>

using namespace std;

int n, p;
string s;

int main() {
#ifndef ONLINE_JUDGE
	//freopen("in.txt", "r", stdin);
#endif
	cin >> n >> p >> s;
	if (p==1) {
		cout << "NO" << endl;
	} else if (p==2) {
		if (s=="a") cout << "b";
		else if (s=="ab") cout << "ba";
		else cout << "NO";
	} else {
		int j=n-1, c=0;
		bool flag=false;
		for (; j>=0&&!flag; j--) for (c=s[j]-'a'+1; c<p; c++){
			if ((j==0||c!=s[j-1]-'a')&&(j<=1||c!=s[j-2]-'a')) {
				flag=true;
				break;
			}
		}
		j++;
		if (flag) {
			s[j]=c+'a';
			for (int i=j+1; i<n; i++) {
				for (c=0; c<p; c++){
					if ((i==0||c!=s[i-1]-'a')&&(i<=1||c!=s[i-2]-'a')) {
						s[i]=c+'a';
						break;
					}
				}
			}
			cout << s;
		} else cout << "NO";
	}
	return 0;
}