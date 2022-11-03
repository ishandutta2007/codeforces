#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>
#include <cstdio>
#include <cctype>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <complex>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cwchar>
#include <cwctype>
#include <exception>
#include <locale>
#include <numeric>
#include <new>
#include <stdexcept>
#include <limits>
#include <valarray>
#include <conio.h>
#include <memory.h>
#include <windows.h>
#include <set>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <list>
#include <utility>
#include <bitset>
#include <algorithm>
#include <functional>
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define MP make_pair
typedef long long ll;
typedef std::pair<int,int> pii;
using namespace std;
string from_int(int n){
	string ans;
	do{
		ans=(char)(n%10+'0')+ans;
		n/=10;
	}while(n);
	return ans;
}
bool frAtoZ(char c){
	return c>='A'&&c<='Z';
}
bool fr0to9(char c){
	return c>='0'&&c<='9';
}
string rctoaz(string rc){
	string ans,r;
	int c=0,f=0;
	for(f++;fr0to9(rc[f]);f++)r.push_back(rc[f]);
	for(f++;f<rc.length();f++)c=c*10+rc[f]-48;
	do{
		c--;
		ans=(char)((c%26)+65)+ans;
		c/=26;
	}while(c);
	return ans+r;
}
string aztorc(string cr){
	string c,r,ans;
	int f=0;
	for(f=0;frAtoZ(cr[f]);f++)c=c+cr[f];
	for(;f<cr.length();f++)r=r+cr[f];
	ans="R"+r+"C";
	int cnum=0,t=1;
	for(int k=c.length()-1;k>=0;k--){
		cnum+=t*(c[k]-64);
		t*=26;
	}
	return ans+from_int(cnum);
}
void getstr(string &s){
	char c=' ';
	s="";
	while(c==' '||c=='\n')c=getchar();
	do{
		s.push_back(c);
		c=getchar();
	}while(c!=' '&&c!='\n');
}
void putstr(string s){
	rep(k,s.length())putchar(s[k]);
	putchar('\n');
}
int main(){
	int n;
	string s;
	scanf("%d",&n);
	rep(k,n){
		getstr(s);
		int ch=0;
		for(;frAtoZ(s[ch]);ch++);
		for(;ch<s.length()&&fr0to9(s[ch]);ch++);
		if(ch==s.length())s=aztorc(s);else s=rctoaz(s);
		putstr(s);
	}
	return 0;
}