#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
#include<string>
#define INF 0x3f3f3f3f
using namespace std;
int n,a,b;
string s;
int main() {
    cin>>n>>a>>b>>s;
    if(s[a-1]!=s[b-1])puts("1");
    else puts("0");
    return 0;
}