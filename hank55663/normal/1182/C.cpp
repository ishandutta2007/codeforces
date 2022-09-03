#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
int main(){
    map<int,map<char,vector<string> > > m;
    int n;
    scanf("%d",&n);
    char c[1000005];
    for(int i = 0;i<n;i++){
        scanf("%s",c);
        string s(c);
        int cnt=0;
        char last;
        for(int j=0;c[j]!=0;j++){
            if(c[j]=='a'||c[j]=='e'||c[j]=='i'||c[j]=='o'||c[j]=='u'){
                cnt++;
                last=c[j];
            }
        }
        m[cnt][last].pb(s);
    }
    vector<pair<string,string> > v1,v2;
    for(auto it:m){
        string last="";
        for(auto it2:it.y){
            for(int i=0;i<it2.y.size();i+=2){
                if(i==it2.y.size()-1){
                    if(last==""){
                        last=it2.y[i];
                    }
                    else{
                        v1.pb(mp(last,it2.y[i]));
                        last="";
                    }
                }
                else{
                  //  cout<<it2.x<<" "<<it2.y[i]<<" "<<it2.y[i+1]<<endl;
                    v2.pb(mp(it2.y[i],it2.y[i+1]));
                }
            }
        }
    }
    while(v2.size()>v1.size()){
        v1.pb(v2.back());
        v2.pop_back();
    }
    if(v1.size()>=v2.size()){
        printf("%d\n",v2.size());
        for(int i = 0;i<v2.size();i++){
            printf("%s %s\n%s %s\n",v1[i].x.c_str(),v2[i].x.c_str(),v1[i].y.c_str(),v2[i].y.c_str());
        }
    }
}

/*
230
0.5 0.5
0.5 0.25
0.25 0.125
0.25
*/