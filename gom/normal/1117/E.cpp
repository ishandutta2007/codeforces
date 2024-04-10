#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
const int N=1e4+5;
int n,d;
string s,t,sq,bf,sr;
vector<int> to1[N],to2[N];
vector<int> gp1[30],gp2[30][30];
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    cin>>t; n=t.size();
    for(int i=0,j=0;i<n;i++,j++){
        j%=26;
        sq+='a'+j;
    }
    cout<<"? "<<sq<<endl;
    cin>>sr; bf=sr;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(sr[i]==sq[j])
                to1[i].push_back(j);
        }
        gp1[sr[i]-'a'].push_back(i);
    }
    for(int gp=0;gp<26;gp++){
        if(gp1[gp].size()==0) continue;
        int x=gp1[gp][0];
        for(int i=0,j=0;i<to1[x].size();i++,j++){
            j%=26;
            sq[to1[x][i]]='a'+j;
        }
    }
    cout<<"? "<<sq<<endl;
    cin>>sr;
    for(int i=0;i<n;i++){
        for(int j=0;j<to1[i].size();j++){
            if(sr[i]==sq[to1[i][j]])
                to2[i].push_back(to1[i][j]);
        }
        gp2[bf[i]-'a'][sr[i]-'a'].push_back(i);
    }
    for(int gp=0;gp<26;gp++){
        for(int ggp=0;ggp<26;ggp++){
            if(gp2[gp][ggp].size()==0) continue;
            int x=gp2[gp][ggp][0];
            for(int i=0,j=0;i<to2[x].size();i++,j++){
                j%=26;
                sq[to2[x][i]]='a'+j;
            }
        }
    }
    cout<<"? "<<sq<<endl;
    cin>>sr;
    s.resize(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<to2[i].size();j++){
            if(sr[i]==sq[to2[i][j]])
                s[to2[i][j]]=t[i];
        }
    }
    cout<<"! "<<s<<endl;
    return 0;
}