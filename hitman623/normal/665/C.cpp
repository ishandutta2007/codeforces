#include <bits/stdc++.h>

using namespace std;

int main()
{
    char a[200001];
    cin>>a;
    long m=strlen(a),i;
    for(i=1;i<m-1;++i)
     {
         if(a[i]==a[i-1])
        { if(a[i+1]<'y')
            { if(a[i]!=a[i+1]+1) a[i]=a[i+1]+1; else a[i]=a[i+1]+2; }
          else
          {
            if(a[i]=='z') a[i]='a';
            else if(a[i+1]=='y')a[i]='z';
            else if(a[i]=='y') a[i]='a';
            else a[i]='y';
          }
        }
     }
     if(a[i]==a[i-1]) {if(a[i-1]!='z')a[i]=a[i-1]+1;else a[i]=a[i-1]-1;}
    cout<<a;
    return 0;
}