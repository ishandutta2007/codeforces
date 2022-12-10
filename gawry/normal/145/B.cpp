#include<cstdio>
#include<string>
#include<cstring>
using namespace std;
int a1,a2,a3,a4;
string r;
main(){
  scanf("%d %d %d %d",&a1,&a2,&a3,&a4);
  if(a3>a4+1||a4>a3+1){puts("-1");return 0;}
  if(a3==a4||a3==a4+1){
    int all=a3+a4+1,cnt4=all-all/2,cnt7=all/2;
//printf("%d %d %d\n",all,cnt4,cnt7);
    if(a1>=cnt4&&a2>=cnt7){
      string t;
      for(int i=0;i<a1-cnt4;i++)t+="4";
      for(int i=0;i<all;i++){
        t+=i%2?"7":"4";
        if(i%2&&i+2>=all)for(int j=0;j<a2-cnt7;j++)t+="7";
      }
      if(!r.size()||t.size()<r.size()||t.size()==r.size()&&t<r)r=t;
    }
  }
  if(a3==a4||a4==a3+1){
    int all=a3+a4+1,cnt4=all/2,cnt7=all-all/2;
//printf("%d %d %d\n",all,cnt4,cnt7);
    if(a1>=cnt4&&a2>=cnt7){
      string t;
      for(int i=0;i<all;i++){
        t+=i%2?"4":"7";
        if(i==1)for(int j=0;j<a1-cnt4;j++)t+="4";
        if(i%2==0&&i+2>=all)for(int j=0;j<a2-cnt7;j++)t+="7";
      }
      if(!r.size()||t.size()<r.size()||t.size()==r.size()&&t<r)r=t;
    }
  }
  puts(r.size()?r.c_str():"-1");
}