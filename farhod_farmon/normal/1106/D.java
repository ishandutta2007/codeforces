import java.awt.*;
import java.io.*;
import java.util.*;
import java.util.List;

public class Main {

    public static void main(String[] args) throws FileNotFoundException {
        //Scanner input = new Scanner(new FileInputStream("input.txt"));
        //PrintStream output = new PrintStream(new FileOutputStream("output.txt"));
        Scanner input = new Scanner(System.in);

        int n = input.nextInt();
        int m = input.nextInt();
        ArrayList <Integer> []v = new ArrayList[n];
        for(int i = 0; i < n; ++i){
            v[i] = new ArrayList<>();
        }
        for(int i = 0; i < m; ++i){
            int x = input.nextInt() - 1;
            int y = input.nextInt() - 1;
            v[x].add(y);
            v[y].add(x);
        }
        boolean []used = new boolean[n];
        for(int i = 0; i < n; ++i){
            used[i] = false;
        }
        PriorityQueue <Integer> s = new PriorityQueue<>((x, y) -> x - y);
        s.add(0);
        used[0] = true;
        for(int it = 0; it < n; ++it){
            int x = s.poll();
            System.out.print((x + 1) + " ");
            for(int y: v[x]){
                if(used[y] == false){
                    used[y] = true;
                    s.add(y);
                }
            }
        }

        //input.close();
        //output.close();
    }
}