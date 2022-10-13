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

string re;
char s[333];

int main()
{
    int n,i=0,x=0;
    gets(s);
    n=strlen(s);
    while (i<n)
    {
       if (s[i]==',') 
       {
          if (x) re.erase(re.size()-1,1);            
          re+=", "; x=0;
       }
       else
         if (s[i]=='.') 
         {
            if (!re.empty() && re[re.size()-1]!=' ') re+=' ';
            re+="...";
            i+=2; x=0;           
         }          
         else
         {
            if (s[i]>='0' && s[i]<='9') re+=s[i],x=0;
            else
               if (!re.empty() && re[re.size()-1]>='0' && re[re.size()-1]<='9')
                  re+=' ',x=1;
         }
         i++;
    }
    if (re[re.size()-1]==' ') re.erase(re.size()-1,1);
    cout << re << endl;
    //system("pause");
    return 0;
}