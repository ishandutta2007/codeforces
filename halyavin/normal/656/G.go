package main
import "fmt"
func main() {
  r := 0
  var f, m, t int
  fmt.Scan(&f, &m, &t)
  q := make([]int, m)
  for i := 0; i < f; i++ {
    var s string
    fmt.Scan(&s)
    for j := 0; j < m; j++ {
      if s[j] == 'Y' {
        q[j]++
        if q[j] == t {
          r++
        }
      }
    }   
  } 
  fmt.Println(r) // kitten
}