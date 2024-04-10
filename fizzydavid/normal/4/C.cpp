/*
    Author  : JZdavid
    From    : 
    Problem : 
    Time    : 
    Verdict : Accepting
*/
#include<algorithm>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<map>
#include<queue>
#include<stack>
#include<string>
#include<set>
#include<utility>
#include<vector>
using namespace std;
#define ff first
#define ss second
#define pb push_back 
#define mp make_pair
typedef long long ll;
const int INF=1<<28;
const long long LINF=1ll<<61;
map<string,int>m;
int n;
int main()
{
    string s;
    cin>>s;
    map<string,int>a;
    while(cin>>s)
    {
        if(a[s])cout<<s<<a[s]<<endl;
        else cout<<"OK\n";
        a[s]++;
    }
}