#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<ctime>

#define open(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout);
#define _max(a,b) (a>b?a:b)
#define _min(a,b) (a<b?a:b)

using namespace std;
template<class T>
inline void read(T& x)
{
    bool f=false;char ch=getchar();x=0;
    while(ch<48)f=(ch=='-'),ch=getchar();
    while(ch>=48)x=(x<<3)+(x<<1)+ch-48,ch=getchar();
    if(f)x*=-1;
}
char s[233];
int main()
{
	scanf("%s",&s);
	for(int i=0;i<strlen(s);)
	{
		while(s[i] == 'W' && s[i+1] == 'U' && s[i+2] == 'B')i+=3;
		while(!(s[i] == 'W' && s[i+1] == 'U' && s[i+2] == 'B') && i<strlen(s))
		{
			cout<<s[i];
			i++;
		}
		cout<<" ";
	}
	return 0;
}