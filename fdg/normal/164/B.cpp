#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <ctime>
#include <memory.h>
#include <string>
#include <sstream>
#include <map>

#define ll long long

using namespace std;

int f[1000002];
int s[1000002];
int w1[1000002];
int w2[1000002];

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    for(int i=0;i<=1000000;++i) w1[i]=w2[i]=-1;
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;++i) {
        scanf("%d",&f[i]);
        w1[f[i]]=i;
    }
    for(int i=0;i<m;++i) {
        scanf("%d",&s[i]);
        w2[s[i]]=i;
    }
    int ans=0,st=-1,last=-1,len=0;
    for(int i=0;i<n;++i) {
        if (w2[f[i]]==-1) break;
        if (st==-1) {
            st=last=w2[f[i]],len=1;
        }
        else {
            int npos=w2[f[i]];
            if (npos<st) npos+=m;
            if (npos-st+1<=m&&npos>last) {
                ++len;
                last=npos;
            } else break;
        }
        if (len==n||len==m) break;
    }
    ans=len;
    int vcur=len==0 ? -1 : 1;
    for(int i=1;i<n;++i) {
        if (w2[f[i]]==-1) {
            len=0;
            st=last=-1;
            vcur=-1;
            continue;
        }
        if (vcur==-1) {
            for(int j=0;j<n;++j) {
                if (w2[f[(j+i)%n]]==-1) break;
                if (st==-1) {
                    st=last=w2[f[(j+i)%n]],len=1;
                }
                else {
                    int npos=w2[f[(j+i)%n]];
                    if (npos<st) npos+=m;
                    if (npos-st+1<=m&&npos>last) {
                        ++len;
                        last=npos;
                    } else break;
                }
                if (len==n||len==m) break;
            }
            ans=max(ans,len); vcur=1;
        } else {
            st=w2[f[i]]; --len;
            if (last-st>=m) last-=m;
            for(int j=0;j<n;++j) {
                if (w2[f[(i+len)%n]]==-1) break;
                if (st==-1) {
                    st=last=w2[f[(i+len)%n]],len=1;
                }
                else {
                    int npos=w2[f[(len+i)%n]];
                    if (npos<st) npos+=m;
                    if (npos-st+1<=m&&npos>last) {
                        ++len;
                        last=npos;
                    } else break;
                }
                if (len==n||len==m) break;
            }
            ans=max(ans,len); vcur++;
        }
//      cout << i << "  " << len << endl;
    }
    printf("%d\n",ans);
    return 0;
}