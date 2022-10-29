#include<cstdio>
#include<string>
#include<cstring>
#include<iostream>
#include<algorithm>

#define For(i,x,y) for (int i=x;i<y;i++)
using namespace std;

string s;
int Len;

int main()
{
	cin>>s;Len=s.length();
	For(i,0,Len) if ((s[i]-'0')%8==0) return printf("YES\n%c\n",s[i]),0;
	For(i,0,Len) For(j,i+1,Len)
		if (s[i]!='0') if (((s[i]-'0')*10+s[j]-'0')%8==0) return printf("YES\n%c%c\n",s[i],s[j]),0;
	For(i,0,Len) For(j,i+1,Len) For(k,j+1,Len)
		if (s[i]!='0')
			if (((s[i]-'0')*100+(s[j]-'0')*10+s[k]-'0')%8==0) return printf("YES\n%c%c%c\n",s[i],s[j],s[k]),0;
	puts("NO");
}