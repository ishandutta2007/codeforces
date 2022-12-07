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
using namespace std;
char s[101];
int main()
{
	scanf("%s",&s);
	for(int i=0;i<strlen(s);i++)
        if(s[i]>='A' && s[i]<='Z')
            s[i]=char(s[i]+32);
    for(int i=0;i<strlen(s);i++)
        if(!(s[i]=='a'||s[i]=='o'||s[i]=='y'||s[i]=='e'||s[i]=='u'||s[i]=='i'))
            cout<<'.'<<s[i];
    printf("\n");
	return 0;
}