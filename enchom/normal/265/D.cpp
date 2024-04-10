#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long Int;

vector<Int> awestr[100001];
Int remember[100001];
Int rL=0;

int main()
{
    Int i,j;
    Int n;
    Int a;
    Int maxseq=1;
    Int maxhere;
    Int curmax;
    Int ca;
    
    scanf("%I64d",&n);
    
    for (i=1;i<=n;i++)
    {
        scanf("%I64d",&a);
        
        ///cout<<"Number "<<a<<endl;
        
        maxhere=1;
        
        ca=a;
        
        for (j=2;j*j<=ca;j++)
        {
            if (a%j==0)
            {
                while(a%j==0)
                a=a/j;
                
                rL++;
                remember[rL]=j;
                
                ///cout<<"divided by "<<j<<endl;
                
                if (awestr[j].size()>0)
                {
                    ///cout<<"max thing of divisor "<<j<<" is using "<<awestr[j].front()<<endl;
                    curmax=awestr[j].front()+1;
                    
                    ///cout<<"obviously curmax = "<<curmax<<endl;
                    
                    if (curmax>maxhere)
                    {
                        ///cout<<"replacing maxhere"<<endl;
                        ///cout<<"connect with "<<j<<endl;
                        maxhere=curmax;
                    }
                }
            }
        }
        
        if (a>1)
        {
            ///cout<<"additionally"<<endl;
            rL++;
            remember[rL]=a;
            
            if (awestr[a].size()>0)
            {
                curmax=awestr[a].front()+1;
                
                ///cout<<"curmax = "<<curmax<<endl;
                
                if (curmax>maxhere)
                {
                    ///cout<<"exception connecter"<<endl;
                    maxhere=curmax;
                }
            }
        }
        
        if (maxhere>maxseq)
        {
            maxseq=maxhere;
        }
        
        for (j=1;j<=rL;j++)
        {
            awestr[ remember[j] ].push_back(maxhere);
            push_heap( awestr[ remember[j] ].begin() , awestr[ remember[j] ].end() );
        }
        
        rL=0;
    }
    printf("%I64d\n",maxseq);
    return 0;
}