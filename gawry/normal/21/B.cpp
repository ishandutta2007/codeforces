#include<cstdio>
int det(int a,int b,int c,int d){
  return a*d-b*c;
}
int main(){
  int A1,B1,C1,A2,B2,C2;
  scanf("%d %d %d %d %d %d",&A1,&B1,&C1,&A2,&B2,&C2);
  int d=det(A1,B1,A2,B2);
  if(d!=0){
    printf("1\n");
    return 0;
  }
  int dx=det(C1,B1,C2,B2);
  int dy=det(A1,C1,A2,C2);
  bool fail=A1==0&&B1==0&&C1!=0||A2==0&&B2==0&&C2!=0;
  if(fail){
    printf("0\n");
    return 0;
  }
  if(dx!=0||dy!=0){
    printf("0\n");
  }else{
    printf("-1\n");
  }
  return 0;
}