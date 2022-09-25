#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair<int,int> ii;
int n;
ii arr[100005];
int node[200005];
vector<int> neighbour[200005];
int original;
int length; ///length of main chain
int filled;
int main(){
    scanf("%d",&n);
    for (int x=0;x<n;x++){
        scanf("%d",&arr[x].first);
        arr[x].second=(x+1)<<1;
    }
    sort(&arr[0],&arr[n],[](ii i,ii j){
        return i.first>j.first;
    });
    node[0]=arr[0].second-1;
    node[arr[0].first]=arr[0].second;
    length=arr[0].first;
    original=length;
    filled=1;
    for (int x=1;x<n;x++){
        if (filled!=original){
            node[filled]=arr[x].second-1;
            if (filled+arr[x].first>length){
                node[++length]=arr[x].second;
            }
            else{
                neighbour[filled+arr[x].first-1].push_back(arr[x].second);
            }
            filled++;
        }
        else{
            if (arr[x].first==1){
                node[length+1]=arr[x].second-1;
                node[length+2]=arr[x].second;
                length+=2;
            }
            else{
                neighbour[0].push_back(arr[x].second-1);
                neighbour[arr[x].first-2].push_back(arr[x].second);
            }
        }
    }
    for (int x=0;x<length;x++){
        printf("%d %d\n",node[x],node[x+1]);
    }
    for (int x=0;x<=length;x++){
        for (vector<int>::iterator it=neighbour[x].begin();it!=neighbour[x].end();it++){
            printf("%d %d\n",node[x],*it);
        }
    }
}