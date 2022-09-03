#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define ULL unsigned long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define pi acosl(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define less Less
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define MXN 200005
int main(){
    char c[1000005];
    scanf("%s",c);
    int hasdot=0;
    for(int i = 0;c[i]!=0;i++){
        if(c[i]=='.')hasdot=1;
    }
    deque<char> q;
    for(int i = 0;c[i]!=0;i++)q.pb(c[i]);
    if(!hasdot)q.pb('.');
    while(!q.empty()&&q.front()=='0')q.pop_front();
    while(!q.empty()&&q.back()=='0')q.pop_back();
    if(q.empty()){
        printf("0\n");
    }
    else if(q.size()==1&&q.front()=='.'){
        printf("0\n");
    }
    else{
       // if(q.back()=='.')
       // q.pop_back();
        vector<int> v1,v2;
        while(!q.empty()){
            if(q.front()=='.')break;
            v1.pb(q.front()-'0');
            q.pop_front();
        }
        q.pop_front();
        while(!q.empty()){
            v2.pb(q.front()-'0');
            q.pop_front();
        }
        if(v1.empty()){
            int num=1;
            reverse(v2.begin(),v2.end());
            while(v2.back()==0)num++,v2.pop_back();
            printf("%d",v2.back());
            v2.pop_back();
            deque<char> print;
            print.pb('.');
            while(!v2.empty())print.pb(v2.back()+'0'),v2.pop_back();
            while(!print.empty()&&(print.back()=='0'||print.back()=='.'))print.pop_back();
            while(!print.empty())printf("%c",print.front()),print.pop_front();
            printf("E%d\n",-num);
        }
        else{
            printf("%d",v1[0]);
            deque<char> print;
            print.pb('.');
            for(int i = 1;i<v1.size();i++)print.pb(v1[i]+'0');
            for(auto it:v2)print.pb(it+'0');
            while(!print.empty()&&(print.back()=='0'||print.back()=='.'))print.pop_back();
            while(!print.empty())printf("%c",print.front()),print.pop_front();
            if(v1.size()!=1)printf("E%d",v1.size()-1);
            printf("\n");
        }
    }
}
/*

23847657 
23458792534

102334155
111111111 
111111111
*/