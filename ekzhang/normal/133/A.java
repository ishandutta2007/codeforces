/**
 * Created by ezhang on 1/21/17.
 */
import java.util.*;
import java.io.*;

public class CF_133A {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));

        boolean ans = false;
        String line;
        while ((line = br.readLine()) != null) {
            if (line.indexOf('H') != -1 || line.indexOf('Q') != -1 || line.indexOf('9') != -1) {
                ans = true;
            }
        }

        out.println(ans ? "YES" : "NO");
        out.flush();
        System.exit(0);
    }
}