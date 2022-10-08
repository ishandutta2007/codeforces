#include <iostream>
using namespace std;

typedef long long Int;

Int hashtable[200001];

int main()
{
    Int n,m,h;
    Int i,j,id,hash;
    char ch;
    Int total=0;
    
    cin>>h>>m>>n;
    
    for (i=0;i<=200000;i++)
    hashtable[i]=-1;
    
    for (i=1;i<=n;i++)
    {
        cin>>ch;
        cin>>id;
        
        if (ch=='+')
        cin>>hash;
        
        if (ch=='-')
        {
            for (j=1;j<=h;j++)
            {
                if (hashtable[j]==id)
                {
                    hashtable[j]=-1;
                    break;
                }
            }
        }
        else if (ch=='+')
        {
            hash++;
            while (hashtable[hash]!=-1)
            {
                hash=hash+m;
                if (hash>h)
                hash-=h;
                
                total++;
            }
            hashtable[hash]=id;
        }
    }
    cout<<total<<endl;
    return 0;
}