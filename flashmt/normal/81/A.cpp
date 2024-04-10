#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<string>
#include<cstring>
#include<cmath>
#define fr(a,b,c) for(a=b;a<=c;a++)
#define frr(a,b,c) for(a=b;a>=c;a--)
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
using namespace std;
typedef long long ll;
const int dx[]={-1,0,1,0,-1,1,1,-1};
      int dy[]={0,1,0,-1,1,1,-1,-1};

char s[222222],t[222222];

int main()
{
    int i,n=0,l;
    scanf("%s",&s);
    l=strlen(s); 
    fr(i,0,l-1)
    {
        if (n && t[n-1]==s[i]) n--;
        else t[n++]=s[i];    
    }
    fr(i,0,n-1) printf("%c",t[i]);
    cout << endl;
    return 0;
}