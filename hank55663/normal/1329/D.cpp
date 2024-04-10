#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define x first
#define LL long long 
#define y second
#define sqr(x) ((x)*(x))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pdd pair<double,double>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
int S[200005];
void add(int x,int k){
    for(int i = x;i<200005;i+=i&-i){
        S[i]+=k;
    }
   // printf("%d %d\n",x,k);
}
int query(int x){
    int res=0;
    for(int i = x;i>0;i-=i&-i){
        res+=S[i];
    }
    return res;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        set<int> v[26];
        set<int> need;
        set<int> hi;
        char c[200005];
        scanf("%s",c+1);
        int n=strlen(c+1);
        for(int i=1;c[i]!=0;i++){
            if(c[i]==c[i+1]){
                v[c[i]-'a'].insert(i);
                need.insert(i);
            }
            add(i,1);
            hi.insert(i);
        }
        vector<pii> ans;
        while(need.size()){
            if(need.size()==1){
                ans.pb(mp(1,query(*need.begin())));
                while(*hi.begin()<=*need.begin()){
                    add(*hi.begin(),-1);
                    hi.erase(hi.begin());
                }
                ans.pb(mp(1,query(n)));
                while(hi.size()){
                    add(*hi.begin(),-1);
                    hi.erase(hi.begin());
                }
                break;
            }
            int Max=0,Maxi;
            for(int j =0;j<26;j++){
                if(v[j].size()>Max){
                    Max=v[j].size();
                    Maxi=j;
                }
            }
          //  printf("%d %d %d\n",Max,Maxi,v[Maxi].size());
            int ok=0;
            for(int j=0;j<26;j++){
                if(j!=Maxi&&v[j].size()){
                    int x=*v[j].begin();
                    if(v[Maxi].lower_bound(x)!=v[Maxi].end()){
                        int y=*v[Maxi].lower_bound(x);
                        int z=*prev(need.find(y));
                        ans.pb(mp(query(z)+1,query(y)));
                        v[Maxi].erase(y);
                        v[c[z]-'a'].erase(z);
                        need.erase(y);
                        need.erase(z);
                        while(hi.upper_bound(z)!=hi.end()&&*hi.upper_bound(z)<=y){
                            add(*hi.upper_bound(z),-1);
                            hi.erase(hi.upper_bound(z));
                        }
                        ok=1;
                    }
                    else{
                        int y=*v[Maxi].rbegin();
                        int z=*next(need.find(y));
                        ans.pb(mp(query(y)+1,query(z)));
                        v[Maxi].erase(y);
                        v[c[z]-'a'].erase(z);
                        need.erase(y);
                        need.erase(z);
                        while(hi.upper_bound(y)!=hi.end()&&*hi.upper_bound(y)<=z){
                            add(*hi.upper_bound(y),-1);
                            hi.erase(hi.upper_bound(y));
                        }
                        
                        ok=1;
                    }
                    break;
                }
                
            }
            if(!ok){
                int x=*v[Maxi].begin();
                v[Maxi].erase(v[Maxi].begin());
                //int y=*v[Maxi].begin();
                ans.pb(mp(1,query(x)));
                need.erase(x);
                while(hi.size()&&*hi.begin()<=x){
                    add(*hi.begin(),-1);
                    hi.erase(hi.begin());
                    
                }
            }
            //printf("%d %d?\n",ans.back().x,ans.back().y);
        }
        if(query(n)){
            ans.pb(mp(1,query(n)));
            while(hi.size()){
                add(*hi.begin(),-1);
                hi.erase(hi.begin());
            }
        }
        printf("%d\n",ans.size());
        for(auto it:ans){
            printf("%d %d\n",it.x,it.y);
        }
    }

}
/*

*/