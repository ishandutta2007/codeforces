#include <iostream>

using namespace std;

int n,k;
string s;
int p[51];

int main()
{
    cin>>n>>k>>s;
    p[1]=0;
    for(int i=2; i<=n;i++)
    {
        int w=p[i-1];
        while(w>0&&s[i-1]!=s[w])
            w=p[w];
        if(s[i-1]==s[w])
            w++;
        p[i]=w;
    }
    if(p==0)
    {
        for(int i=0; i<k;i++)
            cout<<s;
    }
    else
    {
        cout<<s;
        string pom="";
        for(int i=p[n];i<n;i++)
            pom+=s[i];
        for(int i=0; i<k-1; i++)
            cout<<pom;
    }
    return 0;
}