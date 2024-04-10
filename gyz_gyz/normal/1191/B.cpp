#include<bits/stdc++.h>
using namespace std;
int sol(){string s[3];
	for(int i=0;i<3;++i){cin>>s[i];swap(s[i][0],s[i][1]);}sort(s,s+3);
	if(s[0]==s[1]&&s[1]==s[2])return 0;
	if(s[0][0]==s[1][0]&&s[0][1]+1==s[1][1]&&s[1][0]==s[2][0]&&s[1][1]+1==s[2][1])return 0;
	if((s[0][0]==s[1][0]&&s[1][1]-s[0][1]<=2)||(s[1][0]==s[2][0]&&s[2][1]-s[1][1]<=2))return 1;return 2;
}
int main(){printf("%d\n",sol());}