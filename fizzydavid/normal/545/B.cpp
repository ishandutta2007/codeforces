#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <cmath>
#include <cstdio>
#include <vector>
#include <string>
#include <cctype>
#include <bitset>
#include <cstdlib>
//#include <ctime>
#include <iomanip>
#include <cstring>
#include <climits>
#include <utility>
#include <iostream>
#include <algorithm>
using namespace std;
string s,t;
int cnt,cnt2;
int main(){
	cin>>s>>t;
	for(int i=0;i<s.size();i++){
		if(s[i]!=t[i])cnt++;
	}
	if(cnt&1)cout<<"impossible";
	else{
		for(int i=0;i<s.size();i++){
			if(s[i]!=t[i]){
				cnt2++;
				if(cnt2<=cnt/2)cout<<s[i];
				else cout<<t[i];
			}
			else{
				cout<<'0';
			}
		}
	}
}