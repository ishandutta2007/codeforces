#include<iostream>
using namespace std;
#define abs(x) ((x)>0?(x):-(x))
int T,x1,y1,x2,y2;
int main(){cin>>T;while(T--)cin>>x1>>y1>>x2>>y2,cout<<abs(x1-x2)+abs(y1-y2)+(x1!=x2&&y1!=y2?2:0)<<endl;return 0;}