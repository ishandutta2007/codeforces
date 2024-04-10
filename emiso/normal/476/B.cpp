//EM NOME DE ABELLA
#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;

string s1,s2;
int prob[3][33],c=1;

void iai(int n,int i,int p,string s)
{  
    if(i==s.size())
    {
                   prob[n][p]++;
                   return;
    }

    if(s[i]=='+') iai(n,i+1,p+1,s);
    else if(s[i]=='-') iai(n,i+1,p-1,s);
    else 
    {
         iai(n,i+1,p+1,s);
         iai(n,i+1,p-1,s);
    }
}

int main()
{
    int i;
    memset(prob,0,sizeof(prob));
    double p=0;
    int pos=15;
    cin >> s1 >> s2;
    iai(1,0,15,s1);
    iai(2,0,15,s2);
    for(i=0;i<s2.size();i++) if(s2[i]=='?') c=c*2;
    for(i=4;i<=26;i++) if(prob[1][i]==1)
                       {
                                        p=prob[2][i];
                                        p=p/c;
                        }
                        printf("%.9lf\n",p);
    return 0;
}