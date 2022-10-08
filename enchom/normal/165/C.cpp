#include <iostream>
using namespace std;

typedef long long Int;
Int seen[1000100];

int main()
{
    Int k;
    string s;
    Int i,uk;
    Int total;
    Int ifzero=0;
    
    cin>>k;
    cin>>s;
    
    for (i=0;i<=1000099;i++)
    seen[i]=0;
    
    uk=0;
    
    for (i=0;i<s.length();i++)
    {
        if (s[i]=='0')
        {
            ifzero=ifzero+seen[uk];
            seen[uk]++;
        }
        else
        {
            uk++;
            seen[uk]++;
        }
    }
    ifzero=ifzero+seen[0];
    if (k==0)
    {
        cout<<ifzero<<endl;
        return 0;
    }
    total=seen[k];
    for (i=k;i<=uk;i++)
    {
        if (k!=0)
        total=total+seen[i]*seen[i-k];
        else
        total=total+(seen[i]-1)*seen[i-k];
    }
    cout<<total<<endl;
    return 0;
}