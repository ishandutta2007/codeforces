import java.util.*;
public class Main{
    public static void main(String[] args){
        Scanner s=new Scanner(System.in);
        int a=s.nextInt();
        HashMap<String,Integer> map=new HashMap<String,Integer>();
        String one="";
        String two="";
        for(int i=0;i<a;i++){
            String str=s.next();
            if(map.containsKey(str))map.put(str,map.get(str)+1);
            else{
                if(one.equals(""))one=str;
                else two=str;
                map.put(str,1);
            }
        }
        if(two.equals(""))System.out.println(one);
        else if(map.get(one)<map.get(two))System.out.println(two);
        else System.out.println(one);
    }
}