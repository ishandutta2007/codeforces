#include <iostream>
#include <string>
#include <vector>
using namespace std;
int n,t;
string a,b;

int same;
int diff;
vector<int> s,d;
bool ss[100005];
bool d1[100005];
bool d2[100005];
int main(){
    cin>>n>>t;
    cin>>a>>b;
    
    t=n-t;
    
    for (int x=0;x<n;x++){
       if (a[x]==b[x]) same++,s.push_back(x);
       else diff++,d.push_back(x);
    }
    
    if (t>diff/2+same){
        printf("-1");
        return 0;
    }
    
    if (t<same){
        diff=0;
        same=t;
    }
    else{
        diff=(t-same);
    }
    
    for (int x=0;x<same;x++){
        ss[s[x]]=true;
    }
    
    for (int x=0;x<diff;x++){
        d1[d[x]]=true;
    }
    for (int x=diff;x<diff*2;x++){
        d2[d[x]]=true;
    }
    
    
    for (int x=0;x<n;x++){
        if (ss[x]){
            printf("%c",a[x]);
        }
        else if (d1[x]){
            printf("%c",a[x]);
        }
        else if (d2[x]){
            printf("%c",b[x]);
        }
        else{
            for (int y='a';;y++){
                if (y!=a[x] && y!=b[x]){
                    printf("%c",y);
                    break;
                }
            }
        }
    }
}